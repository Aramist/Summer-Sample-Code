//Order: Top, Top Left, Top Right, Middle, Bottom, Bottom Left, Bottom Right, Dot
int pinArr[] = {12, 11, 13, 10, 6, 5, 8, 9};
const int pinArrLength = 8;

int blank[] = {0, 0, 0, 0, 0, 0, 0, 0};
int zero[] = {1, 1, 1, 0, 1, 1, 1, 0};
int one[] = {0, 1, 0, 0, 0, 1, 0, 0}; //A representation of the one digit using the format specified above
int two[] = {1, 0, 1, 1, 1, 1, 0, 0};
int three[] = {1, 0, 1, 1, 1, 0, 1, 0};
int four[] = {0, 1, 1, 1, 0, 0, 1, 0};
int five[] = {1, 1, 0, 1, 1, 0, 1, 0};
int six[] = {1, 1, 0, 1, 1, 1, 1, 0};
int seven[] = {1, 0, 1, 0, 0, 0, 1, 0};
int eight[] = {1, 1, 1, 1, 1, 1, 1, 0};
int nine[] = {1, 1, 1, 1, 0, 0, 1, 0};

void setup() {
  for(auto i : pinArr)
    pinMode(i, OUTPUT);
}

void writeNumber(int num){
  if( num > 10 )
    num = num % 10;
  if( num < 0 ){
    writeNumber(num + 10);
    return;
  }
  
  switch(num){
    case 0:
      write(zero, pinArrLength, pinArr);
      break;
    case 1:
      write(one, pinArrLength, pinArr);
      break;
    case 2:
      write(two, pinArrLength, pinArr);
      break;
    case 3:
      write(three, pinArrLength, pinArr);
      break;
    case 4:
      write(four, pinArrLength, pinArr);
      break;
    case 5:
      write(five, pinArrLength, pinArr);
      break;
    case 6:
      write(six, pinArrLength, pinArr);
      break;
    case 7:
      write(seven, pinArrLength, pinArr);
      break;
    case 8:
      write(eight, pinArrLength, pinArr);
      break;
    case 9:
      write(nine, pinArrLength, pinArr);
      break;
    default:
      write(blank, pinArrLength, pinArr);
  }
}

void write(int *arr, int length, int *pins){
    for(int i = 0; i < length; i++){
      if(*(arr + i) == 1){
        digitalWrite(*(pins + i), HIGH);
      }else{
        digitalWrite(*(pins + i), LOW);
      }
    }
}

void loop() {
  for(int i = 9; i >= 0; i--){
    writeNumber(i);
    delay(1000);
  }
}
