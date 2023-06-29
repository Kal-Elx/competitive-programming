import 'dart:io';

final lookup = {
  16: '4 + 4 + 4 + 4 = 16',
  8: '4 + 4 + 4 - 4 = 8',
  24: '4 + 4 + 4 * 4 = 24',
  9: '4 + 4 + 4 / 4 = 9',
  0: '4 + 4 - 4 - 4 = 0',
  -8: '4 + 4 - 4 * 4 = -8',
  7: '4 + 4 - 4 / 4 = 7',
  68: '4 + 4 * 4 * 4 = 68',
  1: '4 + 4 / 4 - 4 = 1',
  4: '4 + 4 / 4 / 4 = 4',
  -16: '4 - 4 - 4 * 4 = -16',
  -1: '4 - 4 - 4 / 4 = -1',
  -60: '4 - 4 * 4 * 4 = -60',
  32: '4 * 4 + 4 * 4 = 32',
  17: '4 * 4 + 4 / 4 = 17',
  15: '4 * 4 - 4 / 4 = 15',
  60: '4 * 4 * 4 - 4 = 60',
  256: '4 * 4 * 4 * 4 = 256',
  2: '4 / 4 + 4 / 4 = 2',
  -7: '4 / 4 - 4 - 4 = -7',
  -15: '4 / 4 - 4 * 4 = -15',
  -4: '4 / 4 / 4 - 4 = -4',
};

int readNextLine() => int.parse(stdin.readLineSync()!);

main() {
  final m = readNextLine();

  for (int i = 0; i < m; ++i) {
    final n = readNextLine();
    final equation = lookup[n];
    if (equation == null) {
      print('no solution');
    } else {
      print(equation);
    }
  }
}
