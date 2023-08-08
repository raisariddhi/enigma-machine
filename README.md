# Encryption and Decryption Using the Enigma Machine

The Enigma machine is a historical encryption device that uses rotors to encrypt and decrypt messages. This README explains the basics of how the Enigma machine works and provides examples of encryption and decryption using different configurations.

## Overview

The Enigma machine employs a set of rotors to perform encryption. The rotors are arranged in a specific order, and each rotor can be rotated to change the encryption pattern. The basic steps of the encryption process involve substituting each letter of the plaintext message with a corresponding letter from the rotor configuration.

## Getting Started

To use the Enigma machine for encryption and decryption, you'll need to compile and run the provided C code. Follow these steps:

1. Compile the code using the following command:
   ```
   gcc -g enigma_functions.c enigma_driver.c -Wall
   ```

2. Run the compiled executable:
   ```
   ./a.out
   ```

## Encryption Process

1. Choose the rotors you want to use for encryption and the order in which they will be applied.
2. Specify the number of rotations to apply to the encryption rotors.
3. Enter the message you want to encrypt.

The program will then perform the encryption and display the encrypted message.

## Decryption Process

To decrypt a message that has been encrypted using the Enigma machine, simply follow the same steps as for encryption, but apply the rotors in reverse order. Use the same number of rotations for the decryption process as you used for encryption.

## Example

Here's an example of using the Enigma machine for encryption and decryption:

### Encryption

Message: COMPUTER <br />
Rotors: 66 <br />
Rotations: 0 <br />

Encrypted message: MWHKCAZB

### Decryption

Message: MWHKCAZB <br />
Rotors: 66 <br />
Rotations: 0 <br />

Decrypted message: COMPUTER

### Test Example

Enter the message to be encrypted or decrypted: COMPUTER SCIENCE <br />
Which rotors will be used to encrypt the message: 24 <br />
Enter the number of rotations to apply to the encryption rotors: 5 <br />
The encrypted message is: NCLJMABF XNZBTNB <br />
The decrypted message is: COMPUTER SCIENCE <br />
