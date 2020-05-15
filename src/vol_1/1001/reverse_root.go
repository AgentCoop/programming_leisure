package main
import "fmt"
import "math"

var a [262144]int64

func main() {
	n := 0
	for {
		var x int64
		k, _ := fmt.Scan(&x)
		if k != 1 {
			break
		}
		a[n] = x
		n++
	}
	for n > 0 {
		n--
		fmt.Printf("%.4f\n", math.Sqrt(float64(a[n])))
	}
}