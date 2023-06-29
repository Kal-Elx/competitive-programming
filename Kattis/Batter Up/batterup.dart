import 'dart:io';

String readNextLine() => stdin.readLineSync()!;

main() {
  readNextLine(); // Don't need n.
  final atBats = readNextLine().split(' ').map(int.parse).toList(growable: false);
  final validAtBats = atBats.where((atBat) => atBat != -1).toList(growable: false);
  final sluggingPercentage = validAtBats.reduce((a, b) => a + b) / validAtBats.length;
  print(sluggingPercentage);
}
