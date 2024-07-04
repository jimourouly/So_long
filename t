# Load required assemblies for GUI
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create the form
$form = New-Object System.Windows.Forms.Form
$form.Text = 'AD Computer BitLocker Status'
$form.Size = New-Object System.Drawing.Size(600,400)
$form.StartPosition = 'CenterScreen'

# Create the output box
$outputBox = New-Object System.Windows.Forms.RichTextBox
$outputBox.Location = New-Object System.Drawing.Point(10, 40)
$outputBox.Size = New-Object System.Drawing.Size(560, 310)
$form.Controls.Add($outputBox)

# Create the button
$button = New-Object System.Windows.Forms.Button
$button.Location = New-Object System.Drawing.Point(10, 10)
$button.Size = New-Object System.Drawing.Size(75,23)
$button.Text = 'Check'
$form.Controls.Add($button)

# Button click action
$button.Add_Click({
    $outputBox.Clear()
    $computers = Get-ADComputer -Filter * -Property Name | Select-Object -ExpandProperty Name
    foreach ($computer in $computers) {
        if (Test-Connection -ComputerName $computer -Count 1 -Quiet) {
            $bitLockerStatus = manage-bde -status -cn $computer 2>&1
            if ($bitLockerStatus -match "Fully Encrypted") {
                $outputBox.AppendText("$computer is online and BitLocker is enabled.`n")
            } else {
                $outputBox.AppendText("$computer is online but BitLocker is not enabled.`n")
            }
        } else {
            $outputBox.AppendText("pc $computer is offline.`n")
        }
    }
})

# Show the form
$form.ShowDialog()
