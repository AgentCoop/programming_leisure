package main
import "testing"

func TestSol(t *testing.T) {
	if sol(1,2) != 3 {
		t.Error();
	}
}