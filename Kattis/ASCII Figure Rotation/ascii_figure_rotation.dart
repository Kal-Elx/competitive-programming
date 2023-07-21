import 'dart:io';
import 'dart:math';

main() {
  String? n;
  bool isFirst = true;
  while ((n = stdin.readLineSync()) != '0') {
    if (isFirst) {
      isFirst = false;
    } else {
      stdout.writeln();
    }

    final figure = <List<String>>[];
    int maxLength = 0;
    for (int i = 0; i < int.parse(n!); ++i) {
      final row = stdin.readLineSync()!.split('');
      maxLength = max(maxLength, row.length);
      figure.add(row);
    }
    
    for (int i = 0; i < maxLength; ++i) {
      var spacesToPrint = 0;
      for (int j = figure.length - 1; j >= 0; --j) {
        var char = figure[j].elementAtOrNull(i) ?? ' ';

        if (char == '-') {
          char = '|';
        } else if (char == '|') {
          char = '-';
        }

        if (char == ' ') {
          ++spacesToPrint;
        } else {
          stdout.write('${' ' * spacesToPrint}$char');
          spacesToPrint = 0;
        }
      }
      stdout.writeln();
    }
  }
}
