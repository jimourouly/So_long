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
