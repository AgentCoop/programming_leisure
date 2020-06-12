/**
* The given problem is similiar to the rod-cutting problem https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
* Optimal substructure: a[i] = min(a[i - side * side] + 1), where side from 1 upto <= sqrt(N)
*/
package main

import (
	"fmt"
	"math"
)

func dp(areas []uint32, quadricsAmount uint32) uint32 {
	var i uint32
	tab := make([]uint32, quadricsAmount + 1)

	for i = 1; i <= quadricsAmount; i++ {
		var min uint32 = math.MaxUint32;
		for j := 0; j < len(areas); j++ {
			area := areas[j];
			if area <= i {
				if tab[i - area] + 1 < min {
					min = tab[i - area] + 1
				}
			}
		}
		tab[i] = min
	}

	return tab[quadricsAmount];
}

func sol(quadricsN uint32) {
	var m uint32 = uint32(math.Floor(math.Sqrt(float64(quadricsN))))
	var i uint32
	areas := make([]uint32, m)
	for i = 1; i <= m; i++ {
		areas[i - 1] = i * i
	}
	fmt.Printf("%d\n", dp(areas, quadricsN))
}

func main() {
	var quadricsN uint32
	fmt.Scanf("%d", &quadricsN)
	sol(quadricsN)
}
