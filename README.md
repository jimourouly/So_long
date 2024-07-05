# Load required assemblies for GUI
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create the form
$form = New-Object System.Windows.Forms.Form
$form.Text = 'Statut BitLocker des ordinateurs AD'
$form.Size = New-Object System.Drawing.Size(1200,450) # Adjusted for additional space
$form.StartPosition = 'CenterScreen'

# Create the output box for online computers
$onlineBox = New-Object System.Windows.Forms.RichTextBox
$onlineBox.Location = New-Object System.Drawing.Point(10, 70)
$onlineBox.Size = New-Object System.Drawing.Size(560, 310)
$onlineBox.Text = "Ordinateurs en ligne:`n"
$form.Controls.Add($onlineBox)

# Create the output box for offline computers
$offlineBox = New-Object System.Windows.Forms.RichTextBox
$offlineBox.Location = New-Object System.Drawing.Point(580, 70) # Positioned to the right
$offlineBox.Size = New-Object System.Drawing.Size(560, 310)
$offlineBox.Text = "Ordinateurs hors ligne:`n"
$form.Controls.Add($offlineBox)

# Create the progress bar
$progressBar = New-Object System.Windows.Forms.ProgressBar
$progressBar.Location = New-Object System.Drawing.Point(10, 390)
$progressBar.Size = New-Object System.Drawing.Size(1130, 23) # Span across the form
$form.Controls.Add($progressBar)

# Create the button
$button = New-Object System.Windows.Forms.Button
$button.Location = New-Object System.Drawing.Point(10, 10)
$button.Size = New-Object System.Drawing.Size(75,23)
$button.Text = 'Vérifier'
$form.Controls.Add($button)

# Button click action
$button.Add_Click({
    $onlineBox.Clear()
    $offlineBox.Clear()
    $onlineBox.AppendText("Ordinateurs en ligne:`n")
    $offlineBox.AppendText("Ordinateurs hors ligne:`n")
    $computers = Get-ADComputer -Filter * -Property Name | Select-Object -ExpandProperty Name
    $progressBar.Maximum = $computers.Count
    $progressBar.Value = 0
    foreach ($computer in $computers) {
        if (Test-Connection -ComputerName $computer -Count 1 -Quiet) {
            $bitLockerStatus = manage-bde -status -cn $computer 2>&1
            if ($bitLockerStatus -match "Chiffrement complet") { # Adjust this line for the correct French output
                $onlineBox.AppendText("$computer est en ligne et BitLocker est activé.`n")
            } else {
                $onlineBox.AppendText("$computer est en ligne mais BitLocker n'est pas activé.`n")
            }
        } else {
            $offlineBox.AppendText("PC $computer est hors ligne.`n")
        }
        $progressBar.PerformStep()
    }
})

# Show the form
$form.ShowDialog()
