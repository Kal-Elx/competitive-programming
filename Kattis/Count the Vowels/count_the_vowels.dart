import 'dart:io';

main() => print(stdin.readLineSync()!.split('').where((letter) => 'aeiou'.contains(letter.toLowerCase())).length);
