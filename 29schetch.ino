Код:
#include <SD.h>

int b = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing SD card...");
  pinMode(10, OUTPUT);

  if(!SD.begin(8))
  {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("microSD card is ready");
}

void loop()
{
  File dataFile = SD.open("DATA.TXT", FILE_WRITE);

  if(dataFile)
  {
    for (int a = 0; a < 11; a++)
    {
      dataFile.print(a);
      dataFile.print(" multiplied by two is ");
      b = a * 2;
      dataFile.println(b, DEC);
    }
    dataFile.close();
    Serial.println("Finished writing to file.");
  }
  else
  {
    Serial.println("Error opening DATA.TXT");
  }

  Serial.println("Reading DATA.TXT content:");
  File readFile = SD.open("DATA.TXT");
  if (readFile)
  {
    while (readFile.available())
    {
      Serial.write(readFile.read());
    }
    readFile.close();
  }
  else
  {
    Serial.println("Error reading DATA.TXT");
  }

  while(1);
}
