'use strict';

module.exports = {
    up: async (queryInterface, Sequelize) => {
        await queryInterface.addColumn("empresas", "status", {
            type: Sequelize.ENUM("ACTIVE", "ARCHIVED"),
            allowNull: false,
            defaultValue: "ACTIVE",
        })
    },

    down: async queryInterface => {
        await queryInterface.sequelize.transaction(async transaction =>{
            await queryInterface.removeColumn("empresas", "status", {transaction})
            await queryInterface.sequelize.query("DROP TYPE enum_empresas_status", {transaction})
        })
    }
}