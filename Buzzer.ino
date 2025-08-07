void setup() {
  pinMode(8, OUTPUT); // D8 পিনকে আউটপুট হিসেবে সেট করো
}

void loop() {
  digitalWrite(8, HIGH); // বাজার বাজাও
  delay(1000);           // ১ সেকেন্ড অপেক্ষা
  digitalWrite(8, LOW);  // বাজার বন্ধ করো
  delay(1000);           // আবার ১ সেকেন্ড অপেক্ষা
}