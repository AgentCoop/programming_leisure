package main
import (
	"fmt"
	"math"
)

// The answer for the input value in the range [1..9] equals to the value itself, rather than 1x.
// Seems to be wrong, because the problem clearly states about a product of digits.
func findDigits(N uint64, pos int, Q *uint64) bool {
	if N < 10 {
		*Q += uint64(math.Pow10(pos)) * N
		return true
	}
	for i := 9; i > 1; i-- {
		if N % uint64(i) == 0 {
			if pos == 0 {
				*Q += uint64(i)
			} else {
				*Q += uint64(math.Pow10(pos)) * uint64(i)
			}
			return findDigits(N / uint64(i), pos + 1, Q)
		}
	}
	return false
}

func sol(N uint64) {
	var Q uint64 = 0
	var res bool = false
	if N == 0 { // Edge case 1
		Q = 10
		res = true
	} else {
		res = findDigits(N, 0, &Q)
	}

	if res {
		fmt.Printf("%d\n", Q)
	} else {
		fmt.Println("-1")
	}
}

func main() {
	var N uint64
	fmt.Scanf("%d", &N)
	sol(N)
}
