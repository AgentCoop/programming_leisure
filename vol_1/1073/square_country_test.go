package main

import "testing"

func ExampleSol() {
	sol(344);
	// Output:
	// 3
}

func BenchmarkSol(b *testing.B) {
	sol(59999);
}