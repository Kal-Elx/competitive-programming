import 'dart:io';
import 'dart:math';

class Language {
  Language(String language)
      : digits = language.split(''),
        base = language.length;

  final List<String> digits;
  final int base;

  int toDecimal(String number) {
    var decimal = 0;
    for (int i = 0; i < number.length; ++i) {
      final digit = digits.indexOf(number[i]);
      decimal += digit * (pow(base, number.length - i - 1) as int);
    }
    return decimal;
  }

  String fromDecimal(int decimal) {
    final digits = <String>[];
    while (decimal > 0) {
      final digit = decimal % base;
      digits.add(this.digits[digit]);
      decimal ~/= base;
    }
    return digits.reversed.join('');
  }
}

int readNextLine() => int.parse(stdin.readLineSync()!);

main() {
  final T = readNextLine();

  for (int i = 0; i < T; ++i) {
    final input = stdin.readLineSync()!.split(' ');
    final alienNumber = input[0];
    final sourceLanguage = Language(input[1]);
    final targetLanguage = Language(input[2]);

    final decimal = sourceLanguage.toDecimal(alienNumber);
    final targetNumber = targetLanguage.fromDecimal(decimal);

    print('Case #${i + 1}: $targetNumber');
  }
}
