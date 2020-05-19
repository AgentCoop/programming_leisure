package utils
import (
	"log"
	"os"
)

func SetupTestFixture() {
	fixture, err := os.Open("fixture.txt")
	if err != nil {
		log.Fatal(err)
	}
	os.Stdin = fixture
}