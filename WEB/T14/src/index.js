import ReactDOM from 'react-dom'

import Header from './Components/Header/index'
import Saudacoes from './Components/Saudacoes'
import Votos from './Components/Votos'

const Aplicacao = () => (
    <div>
        <Header/>
        <Saudacoes nome="Rodrigo" ano="2022"/>
        <Votos nome="PHP"/>
        <Votos nome="JavaScript"/>
        <Votos nome="Java"/>
    </div>
)

ReactDOM.render( <Aplicacao/>, document.getElementById('root'));