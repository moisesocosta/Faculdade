import Empresa from "../models/Empresa"

class EmpresasController{
    //Listar
    async index(req, res){
        try{
            const data = await Empresa.findAll({
                limit: 1000,
            })
            return res.json(data)
        }catch(e){
            console.log("Erro: ", e)
        }
    }

    //Recupera uma empresa
    async show(req, res){
        try{
            const id = parseInt(req.params.id)
            const empresa = await Empresa.findByPk(id)
            const status = empresa ? 200:404

            return res.status(status).json(empresa)
        }catch(e){
            console.log("Erro: " + e)
        }
    }

    //Cria uma empresa
    async create(req, res){
        try{
            const {name, site, status} = req.body
            const novaEmpresa = await Empresa.create({
                name, site, status
            })

            return res.status(201).json(novaEmpresa)
        }catch(e){
            console.log("Erro: " + e)
        }
    }

    //Atualiza uma empresa
    async update(req, res){
        try{
            const id = parseInt(req.params.id)
            const {name, site, status} = req.body
            const retornoStatus = id >= 0 ? 200:400

            const empresa = await Empresa.findByPk(id)
            const novaEmpresa = await empresa.update({
                nave, site, status
            })
            return res.status(retornoStatus).json(novaEmpresa)
        }catch(e){
            console.log("Erro: " + e)
        }
    }

    //Excluir uma empresa
    async destroy(req, res){
        try{
            const id = parseInt(req.params.id);
            const empresa = await Empresa.findByPk(id)
            const status = id >= 0 ? 200:404;

            empresa.destroy()
            return res.status(status).json();
        }catch(e){
            console.log("Erro: " + e)
        }
    }
}

export default new EmpresasController();