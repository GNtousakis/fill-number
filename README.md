# fill-zero 

Fill the front of a number with the chosen padding. Default is zero. Build with __nan__.

## Install 

```sh

# With npm 
npm i fill-zero

```

## How to use 

```js 

const fillZero  = require('fill-zero');

fillZero(3, 1) // ~> '001'
fillZero(5, 2) // ~> '00002'

fillZero(4, 1, '#') ~> '###1'
fillZero(4, 20, '#') ~> '##20'
fillZero(4, 20, ' ') ~> '  20'

```

