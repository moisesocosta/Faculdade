import Sequelize, {model} from 'sequelize'

class Contato extends Model{
    static init(sequelize){
        super.init(
            {
                name: Sequelize.STRING,
                email: Sequelize.STRING,
                status: Sequelize.ENUM("ACTIVE", "ARCHIVED")
            },
            {
                sequelize,
            }
        )
    }

    static associate(models){
        this.belongsTo(models.Empresa, {foreignKey: "empresa_id"})
    }
}

export default Contato