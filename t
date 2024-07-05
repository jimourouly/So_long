# Load required assemblies for GUI
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create the form
$form = New-Object System.Windows.Forms.Form
$form.Text = 'Statut BitLocker des ordinateurs AD'
$form.Size = New-Object System.Drawing.Size(1800,450) # Adjusted for additional space
$form.StartPosition = 'CenterScreen'

# Function to copy computer names to clipboard in CSV format
function CopyToClipboard-Csv {
    param ($textBox)
    $csvData = $textBox.Lines -join ','
    [System.Windows.Forms.Clipboard]::SetText($csvData)
}

# Create GUI components for each category
$categories = @('BitLocker Activé', 'BitLocker Non Activé', 'Hors Ligne')
$offsetX = 0
foreach ($category in $categories) {
    $label = New-Object System.Windows.Forms.Label
    $label.Location = New-Object System.Drawing.Point(10 + $offsetX, 10)
    $label.Size = New-Object System.Drawing.Size(560, 20)
    $label.Text = $category
    $form.Controls.Add($label)

    $copyButton = New-Object System.Windows.Forms.Button
    $copyButton.Location = New-Object System.Drawing.Point(10 + $offsetX, 30)
    $copyButton.Size = New-Object System.Drawing.Size(560, 23)
    $copyButton.Text = "Copier les noms en CSV"
    $form.Controls.Add($copyButton)

    $textBox = New-Object System.Windows.Forms.RichTextBox
    $textBox.Location = New-Object System.Drawing.Point(10 + $offsetX, 60)
    $textBox.Size = New-Object System.Drawing.Size(560, 320)
    $form.Controls.Add($textBox)

    $copyButton.Add_Click({
        CopyToClipboard-Csv -textBox $textBox
    })

    $offsetX += 590 # Move to the next column
}

# Array to hold text boxes for easy access
$textBoxes = $form.Controls | Where-Object { $_ -is [System.Windows.Forms.RichTextBox] }

# Create the progress bar
$progressBar = New-Object System.Windows.Forms.ProgressBar
$progressBar.Location = New-Object System.Drawing.Point(10, 390)
$progressBar.Size = New-Object System.Drawing.Size(1750, 23) # Span across the form
$form.Controls.Add($progressBar)

# Fetch and categorize computers
$computers = Get-ADComputer -Filter * -Property Name | Select-Object -ExpandProperty Name
$progressBar.Maximum = $computers.Count
$progressBar.Value = 0
foreach ($computer in $computers) {
    if (Test-Connection -ComputerName $computer -Count 1 -Quiet) {
        $bitLockerStatus = manage-bde -status -cn $computer 2>&1
        if ($bitLockerStatus -match "Chiffrement complet") {
            $textBoxes[0].AppendText("$computer`n") # BitLocker Activated
        } else {
            $textBoxes[1].AppendText("$computer`n") # BitLocker Not Activated
        }
    } else {
        $textBoxes[2].AppendText("$computer`n") # Offline
    }
    $progressBar.PerformStep()
}

# Show the form
$form.ShowDialog()
