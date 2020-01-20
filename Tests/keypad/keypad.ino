#include <Keypad.h>

const byte rows = 4; //four rows
const byte cols = 4; //three columns

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {11, 2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[cols] = {5, 6, 7, 10}; //connect to the column pinouts of the keypad


String input; // user input
String password = "1234"; // current password for safe
String tempPassword = ""; // temporary password for when changing

bool isGateOpen = false; // if the gate is open
bool isChangingPassword = false; // if the character is changing the password

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
  
  Serial.begin(9600);

  closeGate();
}

void loop() {  
  char key = keypad.getKey();
  
  if(!isGateOpen) {  
    closedMenu(key);
  } else {
    if (isChangingPassword) {
      changePassword(key);
    } else {
      openedMenu(key);
    }
  }
}




/*
Changing password menu

Pre:
  char key
Post:
  check the key and run the
  cooresponding functions
*/
void changePassword(char key) {
  Serial.println("Enter new password");
  tempPassword.trim();
  switch(key) {
    case NO_KEY:
      break;
    case 'A':
      Serial.println("Password changed!");
      password = tempPassword;
      tempPassword = "";
      isChangingPassword = false;
      break;
    case 'B':
      printScreen("Cannot include letters in your password.");
      break;
    case 'C':
      isChangingPassword = false;
      Serial.println("Cancelled");
      tempPassword = "";
      break;
    case 'D':
      tempPassword = removeKey(tempPassword)+" ";
      Serial.println(tempPassword);
      break;
    default:
      tempPassword += key;
      Serial.println(tempPassword);
      break;
  }
}

void openedMenu(char key) {
  Serial.println("Gate is opened");
  switch(key) {
    case 'B':
      Serial.println("A to apply");
      Serial.println("C to cancel",0,1);
      isChangingPassword = true;
      break;
    case 'C':
      closeGate();
      break;
    default:
      break;
  }
}

/*
Check the key of the keypad 

Pre:
  char key
Post:
  displays text to the screen
  and calls special functions
*/
void closedMenu(char key) {
  Serial.println("Enter your password:");
  input.trim();
  switch(key) {
    case 'A':
      checkPassword();
      break;
    case 'D':
      input = removeKey(input)+" ";
      Serial.println(input);
      break;
    case NO_KEY:
    case 'C':
    case 'B':
      Serial.println(input);
      break;
    default:
      input += key;
      Serial.println(input);
      break;
  } 
}

/*
Closes the safe

Post:
  Sets isOpenGate to false, and turns the motor
  to the closed position, also sets the user input
  to 0, tells the rfid file the gate is now closed
  and changes rgb led to red
*/
void closeGate() {
  digitalWrite(outputPin, LOW);
  input = "";
  Serial.println("Closing the gate");
  isGateOpen = false;
}

/*
Checks the input if it is equal to
the password

Post:
  Turns isOpenGate to true 
  and call openGate function
*/
void checkPassword() {
  input.trim();
  if (input == password) {
    isGateOpen = true;
    Serial.println("Correct password");
    openGate();
    delay(1000);
  } else {
    input = "";
    Serial.println("Incorrect password");
  }
}

/*
Opens the gate

Post:
   Moves the motor to the 
   open position, sends HIGH to the
   output pin to signify the gate is
   open to the rfid file and 
   changes rgb to green
*/ 
void openGate() {
  Serial.println("Gate is opened");
}

/*
Removes a key from a String

Pre:
  The string to remove the character from
Post: 
  Returns a string with one less character
*/
String removeKey(String str) { 
  return str.substring(0,str.length()-1);
}
