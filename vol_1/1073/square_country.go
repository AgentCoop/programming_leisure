package main

import (
	"fmt"
)

const N = 60000
const MAX_SIDE = 244
// The goal is to minimize the number of terms in Sum(pi ^ 2)
// Initialize first three elements of 1-indexed array.
// For 1 quadrics you can buy 1 square meter, for 2 - 2 with two certificates
var answers [N]uint32 = [N]uint32{0,1,2,3}

func findClosestBestAnswer(amount uint32) uint32 {
	var i uint32
	for i = amount; i > 0; i-- {
		if answers[i] == 1 {
			return i
		}
	}
	return 0
}

func V(amount uint32) uint32 {
	//if amount == 1 { return 1 }
	//if amount == 2 { return 2 }
	//if amount == 3 { return 3 }

	var nCertifs uint32 = answers[amount]
	if nCertifs > 0 { // Best answer
		return nCertifs
	} else {
		var i uint32
		for i = 3; i < amount; i++ {
			a := V(i)
			b := V(amount - i)
			if answers[amount] > a + b || answers[amount] == 0 {
				answers[amount] = a + b
			}
		}
	}

	return answers[amount]
}

func sol(quadricsN uint32) {
	for i := 2; i <= MAX_SIDE; i++ {
		answers[i * i] = 1
		answers[i * i + 1] = 1
	}
	V(quadricsN)
	fmt.Printf("%d\n", answers[quadricsN])
}

func main() {
	//var quadricsN uint32
	//fmt.Scanf("%d", &quadricsN)
	//sol(quadricsN)
	sol(59999)
}
