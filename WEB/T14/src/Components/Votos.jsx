import {useState} from "react";

export default function Votos(props){
    const [voto, setVoto] = useState(0);

    const contaVoto = () => {
        setVoto(voto + 1);
    }

    return(
        <div>
            {props.name}({voto})<button onClick={contaVoto}>+1</button>
        </div>
    )
}