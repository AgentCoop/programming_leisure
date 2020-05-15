package main
import "testing"
import "acm_timus/utils"

func TestSol(t *testing.T) {
	if sol(1,2) != 3 {
		t.Error();
	}
}