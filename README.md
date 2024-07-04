# So_long

Nom de l’ordinateur : 20240628-1

Volumes de disques pouvant être protégés avec le
Chiffrement de lecteur BitLocker :
Volume C: [Windows ]
[Volume du système d’exploitation]

    Taille :                     475.59 Go
    Version de BitLocker :       2.0
    État de la conversion :      Espace utilisé uniquement chiffré
    Pourcentage chiffré :        100.0%
    Méthode de chiffrement :     XTS-AES 128
    État de la protection :      Protection activée
    État du verrouillage :       Déverrouillé
    Champ d’identification :     Inconnu
    Protecteurs de clés :
        Mot de passe numérique
        TPM


# Store the text in a variable
$text = @"
Nom de l’ordinateur : 20240628-1

Volumes de disques pouvant être protégés avec le Chiffrement de lecteur BitLocker : Volume C: [Windows ] [Volume du système d’exploitation]

Taille :                     475.59 Go
Version de BitLocker :       2.0
État de la conversion :      Espace utilisé uniquement chiffré
Pourcentage chiffré :        100.0%
Méthode de chiffrement :     XTS-AES 128
État de la protection :      Protection activée
État du verrouillage :       Déverrouillé
Champ d’identification :     Inconnu
Protecteurs de clés :
    Mot de passe numérique
    TPM
"@

# Use regex to find the hostname
if ($text -match "Nom de l’ordinateur : (\S+)") {
    $hostname = $matches[1]
}

# Use regex to find the protection status
if ($text -match "État de la protection : (\w+ \w+)") {
    $protection = $matches[1]
}

# Print the extracted information
Write-Host "hostname : $hostname"
Write-Host "Protection : $protection"


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
