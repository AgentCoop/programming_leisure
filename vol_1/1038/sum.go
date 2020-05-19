package main
import (
	"fmt"
	"math"
)

func sol(N int) {
	var sum float64
	absN := math.Abs(float64(N))
	sum = 0
	if N == 0 || N == 1 {
		sum = 1
	} else if N < -1 {
		sum = absN * (1 + absN) / 2
		sum -= 1;
		sum = -1 * sum;
	} else if N > 1 {
		sum = absN * (1 + absN) / 2
	}
	fmt.Printf("%.0f\n", sum)
}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	sol(N)
}