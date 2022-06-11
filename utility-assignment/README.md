
![Screenshot from 2022-06-04 11-30-56](https://user-images.githubusercontent.com/105910992/171986760-e86ce737-da0c-4f15-ac18-1089bc4d6209.png)

using copy utility "cps" and " cpl " performing 1GB file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 2m14s.997s    |3m07.9s|
| 1000000       |  7.8850s      | 41.6  |
| 1000000000    |   0.766s      |0.4733 |



using copy utility "cps" and " cpl " performing 400mb file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 5.833s        |19.647s|
| 1000000       |  0.743s       |8.953s |
| 1000000000    |   0.431s      |0.2533s|

using copy utility "cps" and " cpl " performing 1mb file operations
|     buf size  |      cps      | cpl   |
| ------------- |:-------------:| -----:|
| 1000bytes     | 0.4699s       | 0.745 |
| 1000000       |  0.003        | 0.177 |
| 1000000000    |   0.455       | 0.427 |


