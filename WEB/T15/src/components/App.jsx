import { useState } from "react";

export default function App(){

  const [counter, setCounter] = useState();

  function incremento(){
    setCounter((prevState) => prevState + 1);
  }

  function decremento(){
    setCounter((prevState) => prevState - 1);
  }

  return (
    <div>
      <h1>{counter}</h1>
      <button onClick={incremento}>+</button>
      <button oncClick={decremento}>-</button>
    </div>
  )
}
