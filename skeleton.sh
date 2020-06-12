#! /bin/bash

VOL_DIR="$1"
PROB_NUM="$2"
PROB_NAME="$3"
PROB_DIR="vol_${VOL_DIR}/${PROB_NUM}"
mkdir -p $PROB_DIR

cat << EOF > "${PROB_DIR}/${PROB_NAME}.go"
package main
import (
	"fmt"
	"math"
)

func sol(N int) {

}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	sol(N)
}
EOF

cat << EOF > "${PROB_DIR}/${PROB_NAME}_test.go"
package main
import "github/acm_timus/utils"

func ExampleSol() {
	utils.SetupTestFixture()
	sol(-3);
	// Output:
	// -5
}

EOF

touch "${PROB_DIR}/readme.md"
touch "${PROB_DIR}/fixture.txt"