int fibonacci(int n) {
  if (n <= 1) return n;  // Base case: fib(0) = 0, fib(1) = 1
  return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
}

void setup() {
  Serial.begin(9600);  // Start serial communication
  delay(1000);  // Wait for Serial Monitor to initialize

  int N = 10;  // Number of Fibonacci terms to print

  for (int i = 0; i < N; i++) {
    Serial.print("Fibonacci(");
    Serial.print(i);
    Serial.print(") = ");
    Serial.println(fibonacci(i));  // Print Fibonacci number using recursive function
    delay(500);  // Small pause to see the output
  }
}

void loop() {
  // Nothing needed here
}
