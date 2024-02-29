const int pins[8] = {2,3,4,5,6,7,8,9};

byte display[10][7] = {
  {1,1,1,1,1,1,0}, //Digito 0
  {0,1,1,0,0,0,0}, //Digito 1
  {1,1,0,1,1,0,1}, //Digito 2
  {1,1,1,1,0,0,1}, //Digito 3
  {0,1,1,0,0,1,1}, //Digito 4
  {1,0,1,1,0,1,1}, //Digito 5
  {1,0,1,1,1,1,1}, //Digito 6
  {1,1,1,0,0,0,0}, //Digito 7
  {1,1,1,1,1,1,1}, //Digito 8
  {1,1,1,0,0,1,1} //Digito 9
};


void setup()
{
  Serial.begin(9600);
  for(int i=0; i<8; i++){
  	pinMode(pins[i], OUTPUT);
  }
  digitalWrite(pins[7], LOW);

}

void loop()
{
  char c = Serial.read();
  String s = String(c);
  int n = s.toInt();
  	Serial.println(n);
  ligaDisplay(n);
  delay(2000);
  
  /*for(int i = 0; i < 10; i++){
  	ligaDisplay(i);
    delay(2000);
  }*/
}

void ligaDisplay(int n){
  for(int i = 0; i< 7; i++){
    digitalWrite(pins[i], display[n][i]);
  }
}