# 1008. Image Encoding
  * Time limit: 2.0 second
  * Memory limit: 64 MB
There are several ways to encode an image. In this problem we will consider two representations of an image. We assume that the image consists of black and white pixels. There is at least one black pixel and all black pixels are connected with their sides. Coordinates of black pixels are not less than 1 and not greater than 10. An example of such an image is on the figure.
Both representations describe an arrangement of black pixels only.
At the first representation we specify in the first line number of black pixels and coordinates of each black pixel in the following lines. Pixels are listed in order of increasing X. In case of equality of X they are listed in order of increasing Y. Image at the figure is encoded as follows:
6
2 3
2 4
3 3
3 4
4 2
4 3
At the second representation we specify in the first line coordinates of the lowest left black pixel. Each of the following lines contains a description of neighbors for one of the pixels. At first, neighbors of the lowest left pixel are specified, then neighbors of its first neighbor (if it exists) are specified, then neighbors of its second neighbor (if it also exists) follow. When all its neighbors are described the description of the neighbors of its first neighbor follows. The description of the neighbors of its second neighbor follows then and so on.
Each descriptive line contains at most one letter for each neighbor: R for the right, T for the top, L for the left, B for the bottom. If the neighbor was already specified it is not included into the descriptive line and vice-versa. Also, there is only one descriptive line for each pixel. Neighbors are listed counter-clockwise starting with the right. Each descriptive line except the last ends with a comma. The last line ends with a full stop. The image on the figure is encoded as follows:
2 3
RT,
RT,
,
B,
,
.
There are no leading or trailing spaces in any representation. There is exactly one space between X and Y coordinates.
## Input
One representation of the image will be given to your program in the input.
## Output
Your program has to write other representation of the image to the output.