#include "enigma.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const char *ROTOR_CONSTANTS[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};

// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[]){
    //https://www.cs.miami.edu/home/harald/enigma/enigma.c    
    int c, i = 0;
    // while loop runs till we get all the characters till the new line
    while((c = getchar()) != '\n'){
      //converting all the characters in the message to upper case
      msg[i] = toupper(c);
      i++;
    }

    //ending the message with a null charcter instead of a new line
    msg[i] = '\0';
    return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 8. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[]){
    char temp;
    int i = 0;
    //the while loop takes all the characters till a new line is encountered
    while(temp != '\n'){
        scanf("%c", &temp);
        if(temp == '\n'){
            break;
        }else{
            which_rotors[i] = temp;
            i++;
        }
    }
    // ending the array with a null character instead of a new line
    which_rotors[i] = '\0';
    //returns the number of characters (number of rotors) in the array
    return i;
} 

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors. The input will be between 0 and 25 inclusive
int Get_Rotations(){
    int numRotations;
    //taking the number of rotations from the user as input
    scanf(" %d", &numRotations);
    return numRotations;
}


// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5]){
    int i = 0;
    //the while loop runs till the null character is encountered in the which_rotors array which contains
    //the rotor number which will be used for encryption
    while(which_rotors[i] != '\0'){
        for(int index = 0; index < 27; index++){
            // storing the rotors into encryption_rotors
            encryption_rotors[i][index] = ROTOR_CONSTANTS[which_rotors[i] - '0'][index];
        }
        i++;
    }
    return;
}


// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27]){
    int row = 0;
    //this loop is used to rotate the rotors in the encryption_rotors rotations number of times
    for(int k = 0; k < rotations; k++){
        row = 0;
        // the while loop runs till the last row of encryption_rotors is reached
        while(row < 4){
            char temp[27];
            //right rotating the string by one character and storing it in a temporary array
            temp[0] = encryption_rotors[row][25];
            for(int i = 1; i < 26; i++){
                temp[i] = encryption_rotors[row][i-1];  
            }
            temp[26] = '\0';
            // copying the temporary array into the encryption_rotors array
            for(int i = 0; i < 27; i++){
                encryption_rotors[row][i] = temp[i];
            }
            row++;
        }
        
    }

    return;
}
// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encryped_msg 
// Do not change spaces, make sure your encryped_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[]){
    int row = 0; 
    int count = 0;
    // copying the message into the encrypted_msg    
    for(int i = 0; msg[i] != '\0'; i++){
        encrypted_msg[i] = msg[i];
        count++;
    }
    //ending the encrypted_msg with null character instead of new line
    encrypted_msg[count] = '\0';
    // the while loop runs for all the rotors entered by the user
    while(row < num_active_rotors){
        for(int j = 0; encrypted_msg[j] != '\0'; j++){
            // If it is a space it ignores it
            if(encrypted_msg[j] == ' '){
                continue;
            }
            // otherwise it encrypts it and stores it in encrypted_msg
            else{
                encrypted_msg[j] = encryption_rotors[row][encrypted_msg[j] - 'A'];

            }
        }
        row++;
    }
    return;
}


// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) {
    int row = num_active_rotors - 1;
    int count = 0;
    //copying the encrypted msg into decrypted_msg
    for(int i = 0; encrypted_msg[i] != '\0'; i++){
             decrypted_msg[i] = encrypted_msg[i];
             count++;
    }
    //ending the decrypted_msg with a null character instead of a new line
    decrypted_msg[count] = '\0';
    // the while loop goes backwards from the last rotor to the first rotor for decryption
    while(row >= 0){
        //if the character is a space it is ignored
        for(int j = 0; decrypted_msg[j] != '\0'; j++){
            if(decrypted_msg[j] == ' '){
                continue;
            }
            //otherwise it is decrypted and break out of the loop to avoid overwriting of the decrypted character
            else{
                for(int i = 0; i < 26; i++){
                    if(decrypted_msg[j] == encryption_rotors[row][i]){
                        decrypted_msg[j] = i + 'A';
                        break;
                    }
                }
            }
        }
        row--;
    }
    return;
}
