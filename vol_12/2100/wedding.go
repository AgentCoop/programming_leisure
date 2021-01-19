package main

import (
	"fmt"
	"io"
	"os"
	"strings"
)

func calcTotalAmount() {
	var N int
	for {
		_, err := fmt.Scanf("%d\n", &N)
		if err == io.EOF {
			return
		}
		nGuests := 2
		var line string
		for i := 0; i < N; i++ {
			fmt.Fscanf(os.Stdin, "%s\n", &line)
			if strings.Contains(line, "+one") {
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
