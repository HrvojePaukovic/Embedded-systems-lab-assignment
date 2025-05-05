int i = 0, j = 1, k = 0;
int fib = 0;
int N = 10;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  if (i < N) {
    Serial.print("Fibonacci(");
    Serial.print(i);
    Serial.print(") = ");
    Serial.println(fib);

    fib = j + k;
    j = k;
    k = fib;
    i++;

    delay(500);  // Small pause so you can see each line print
  }
}
