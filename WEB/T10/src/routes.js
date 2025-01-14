import { Router } from "express"
const routes = new Router()

import empresas from "./app/controllers/EmpresasController"

routes.get("/empresas", empresas.index)
routes.get("/empresas/:id", empresas.show)
routes.post("/empresas", empresas.create)
routes.put("/empresas/:id", empresas.update)
routes.delete("/empresas/:id", empresas.destroy)

export default routes;