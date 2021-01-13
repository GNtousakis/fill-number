# fill-number 

Fill the front of a number with the chosen padding. Default is zero. Build with __nan__.

## Install 

```sh

# With npm 
npm i fill-number

```

## How to use 

```js 

const fillNumber  = require('fill-number');

fillNumber(3, 1) // ~> '001'
fillNumber(5, 2) // ~> '00002'

fillNumber(4, 1, '#') // ~> '###1'
fillNumber(4, 20, '#') // ~> '##20'
fillNumber(4, 20, ' ') // ~> '  20'

```

