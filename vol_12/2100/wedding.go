package main

import (
	"fmt"
	"io"
	"os"
)

func calcTotalAmount() {
	var N int
	var line string
	for {
		_, err := fmt.Scanf("%d\n", &N)
		if err == io.EOF {
			return
		}
		nGuests := 2
		for i := 0; i < N; i++ {
			fmt.Fscanf(os.Stdin, "%s\n", &line)
			j := len(line)
			// strings.Contains(line, "+one")
			if j > 4 && int(line[j-4])== int('+') && int(line[j-3]) == int('o') && int(line[j-2])==int('n')&&int(line[j-1])==int('e') {
				nGuests += 2
			} else {
				nGuests++
			}
		}
		if nGuests == 13 {
			nGuests++
		}
		fmt.Printf("%d\n", nGuests * 100)
	}
}

func main() {
	calcTotalAmount()
}
