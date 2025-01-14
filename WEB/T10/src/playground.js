import {Op} from "sequelize"
import "./database"

import Empresa from "./app/models/Empresa"
import Contato from "./app/models/Contato"

class Playground{
    static async play(){
        const empresa = await Empresa.findByPk({
            include: [
                {
                    model: Contato,
                    where: {
                        status: "ARCHIVED",
                    },
                    required: false,
                }
            ],
            where: {
                status: {
                    [Op.or]: ["ACTIVE", "ARCHIVED"]
                }
            }
        })
        
        console.log(JSON.stringify(empresas, null, 2))

    }
}

Playground.play()