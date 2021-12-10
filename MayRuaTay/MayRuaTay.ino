#include <SimpleSDAudio.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <math.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Tin hieu dieu khien may bom
int bom = 6;

//Dau vao cam bien hong ngoai
int hongngoai = 7;

//Dau vao cam bien sieu am
int trig = 5;
int echo = 8;

//CS the nho
int cs = 10;

//Led trang thai
int cho_led = 4;
int chao_led = 3;
int bom_led = 2;

unsigned long t;

void setup() {
  Serial.begin(9600);
  pinMode(bom, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(hongngoai, INPUT);

  SdPlay.setSDCSPin(cs); // Enable if your SD card CS-Pin is not at Pin 4...
  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);

  pinMode(cho_led, OUTPUT);
  pinMode(chao_led, OUTPUT);
  pinMode(bom_led, OUTPUT);
  mlx.begin();

  //  //Moi nuoc
  //  digitalWrite(bom, HIGH);
  //  delay(1000);
  //  digitalWrite(bom, LOW);
}

void loop() {
  if (digitalRead(hongngoai) && readPing() >= 8 && millis() - t > 30000) {
    chao_status();
    return;
  }
  if (readPing() < 8) {
    bom_status();
    return;
  }
  cho_status();
}

void cho_status() {
  Serial.println("Cho status");
  digitalWrite(cho_led, HIGH);
  digitalWrite(chao_led, LOW);
  digitalWrite(bom_led, LOW);
}

void chao_status() {
  Serial.println("Chao status");
  digitalWrite(cho_led, LOW);
  digitalWrite(chao_led, HIGH);
  digitalWrite(bom_led, LOW);

  //Phat cau chao
  SdPlay.setFile("hello.wav");
  SdPlay.play();
  delay(6000);

  t = millis();
}

void bom_status() {
  Serial.println("Bom status");
  digitalWrite(cho_led, LOW);
  digitalWrite(chao_led, LOW);
  digitalWrite(bom_led, HIGH);

  delay(350);
  //Lay nhiet do co the
  float get_temp = mlx.readObjectTempC() + 4.7;
  float temp = lam_tron(get_temp);
  Serial.println(temp);

  //Bom dung dich sat khuan
  digitalWrite(bom, HIGH);
  delay(330);
  digitalWrite(bom, LOW);

  delay(1000);

  //Doc nhiet do co the
  if (temp == 36) {
    SdPlay.setFile("saukhong.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.1) {
    SdPlay.setFile("saumot.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.2) {
    SdPlay.setFile("sauhai.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.3) {
    SdPlay.setFile("sauba.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.4) {
    SdPlay.setFile("saubon.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.5) {
    SdPlay.setFile("saunam.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.6) {
    SdPlay.setFile("sausau.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.7) {
    SdPlay.setFile("saubay.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.8) {
    SdPlay.setFile("sautam.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 36.9) {
    SdPlay.setFile("sauchin.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37) {
    SdPlay.setFile("baykhong.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.1) {
    SdPlay.setFile("baymot.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.2) {
    SdPlay.setFile("bayhai.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.3) {
    SdPlay.setFile("bayba.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.4) {
    SdPlay.setFile("baybon.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.5) {
    SdPlay.setFile("baynam.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.6) {
    SdPlay.setFile("baysau.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.7) {
    SdPlay.setFile("baybay.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.8) {
    SdPlay.setFile("baytam.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 37.9) {
    SdPlay.setFile("baychin.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 38) {
    SdPlay.setFile("tamkhong.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 38.1) {
    SdPlay.setFile("tammot.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  if (temp == 38.2) {
    SdPlay.setFile("tamhai.wav");
    SdPlay.play();
    delay(5000);
    return;
  }
  //  if (temp == 38.3) {
  //    SdPlay.setFile("tamba.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.4) {
  //    SdPlay.setFile("tambon.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.5) {
  //    SdPlay.setFile("tamnam.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.6) {
  //    SdPlay.setFile("tamsau.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.7) {
  //    SdPlay.setFile("tambay.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.8) {
  //    SdPlay.setFile("tamtam.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 38.9) {
  //    SdPlay.setFile("tamchin.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
  //  if (temp == 39) {
  //    SdPlay.setFile("chink.wav");
  //    SdPlay.play();
  //    delay(5000);
  //    return;
  //  }
}

float lam_tron(double temp) {
  int new_temp = temp * 100;
  int chuc, donvi, thapphan;

  chuc = new_temp / 1000;
  new_temp = new_temp % 1000;

  donvi = new_temp / 100;
  new_temp = new_temp % 100;

  thapphan = new_temp / 10;

  return (chuc * 10 + donvi + (float)thapphan / 10);
}

int readPing() {
  unsigned long duration; // biến đo thời gian
  int distance;           // biến lưu khoảng cách

  /* Phát xung từ chân trig */
  digitalWrite(trig, 0);  // tắt chân tri
  delayMicroseconds(2);
  digitalWrite(trig, 1);  // phát xung từ chân tri
  delayMicroseconds(5);   // xung có độ dài 5 microSecond
  digitalWrite(trig, 0);  // tắt chân tri

  /* Tính toán thời gian */
  // Đo độ rộng xung HIGH ở chân echo.
  duration = pulseIn(echo, HIGH);
  // Tính khoảng cách đến vật
  distance = int(duration / 2 / 29.412);

  /* In kết quả ra Serial Monitor */
  return distance;
  delay(200);
}
