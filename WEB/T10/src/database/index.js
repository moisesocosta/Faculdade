import Sequelize from "sequelize"
import config from "../config/database"
import Empresa from "../app/models/Empresa"
import Contato from "../app/models/Contato"

const models = [Empresa, Contato]

class Database{
    constructor(){
        this.connection = new Sequelize(config)

        this.init()
        this.associate()
    }

    init(){
        models.forEach(model => model.init(this.connection))
    }

    associate(){
        models.forEach(model => {
            if(model.associate){
                model.associate(this.connection.models)
            }
        })
    }
}

export default new Database()