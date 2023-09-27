package main

import "fmt"

func main() {
	var res, ones, branches int = 0, 0, 1

	var sequence string
	fmt.Scanln(&sequence)

	for i := 0; i < len(sequence); i++ {
		var c byte = sequence[i]

		if c == '0' {
			res = (res + ones) % 1000000007
		} else if c == '1' {
			ones = (ones + branches) % 1000000007
		} else {
			res = (2*res + ones) % 1000000007
			ones = (2*ones + branches) % 1000000007
			branches = (2 * branches) % 1000000007
		}
	}

	fmt.Println(res)
}
