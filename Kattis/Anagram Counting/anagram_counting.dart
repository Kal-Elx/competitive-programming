import 'dart:io';

final factorialCache = <int, BigInt>{
  0: BigInt.one,
};

BigInt factorial(int n) {
  if (factorialCache.containsKey(n)) {
    return factorialCache[n]!;
  }
  final N = BigInt.from(n);
  final res = N * factorial(n - 1);
  factorialCache[n] = res;
  return res;
}

main() {
  String? word;
  while ((word = stdin.readLineSync()) != null) {
    final letterCount = <String, int>{};
    for (final letter in word!.split('')) {
      letterCount[letter] = (letterCount[letter] ?? 0) + 1;
    }
    final numerator = factorial(word.length);
    final denominator = letterCount.values.fold(BigInt.one, (a, b) => a * factorial(b));
    print(numerator ~/ denominator);
  }
}
