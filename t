# Load required assemblies for GUI
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create the form
$form = New-Object System.Windows.Forms.Form
$form.Text = 'Statut BitLocker des ordinateurs AD'
$form.Size = New-Object System.Drawing.Size(600,450)
$form.StartPosition = 'CenterScreen'

# Create the output box
$outputBox = New-Object System.Windows.Forms.RichTextBox
$outputBox.Location = New-Object System.Drawing.Point(10, 70)
$outputBox.Size = New-Object System.Drawing.Size(560, 310)
$form.Controls.Add($outputBox)

# Create the progress bar
$progressBar = New-Object System.Windows.Forms.ProgressBar
$progressBar.Location = New-Object System.Drawing.Point(10, 390)
$progressBar.Size = New-Object System.Drawing.Size(560, 23)
$form.Controls.Add($progressBar)

# Create the button
$button = New-Object System.Windows.Forms.Button
$button.Location = New-Object System.Drawing.Point(10, 10)
$button.Size = New-Object System.Drawing.Size(75,23)
$button.Text = 'Vérifier'
$form.Controls.Add($button)

# Button click action
$button.Add_Click({
    $outputBox.Clear()
    $computers = Get-ADComputer -Filter * -Property Name | Select-Object -ExpandProperty Name
    $progressBar.Maximum = $computers.Count
    $progressBar.Value = 0
    foreach ($computer in $computers) {
        $outputBox.AppendText("PC $computer est testé...`n")
        $outputBox.ScrollToCaret()
        if (Test-Connection -ComputerName $computer -Count 1 -Quiet) {
            $bitLockerStatus = manage-bde -status -cn $computer 2>&1
            if ($bitLockerStatus -match "Chiffrement complet") { # Adjust this line for the correct French output
                $outputBox.AppendText("$computer est en ligne et BitLocker est activé.`n")
            } else {
                $outputBox.AppendText("$computer est en ligne mais BitLocker n'est pas activé.`n")
            }
        } else {
            $outputBox.AppendText("PC $computer est hors ligne.`n")
        }
        $progressBar.PerformStep()
    }
})

# Show the form
$form.ShowDialog()
