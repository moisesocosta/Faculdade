'use strict';

module.exports = {
    up: async (queryInterface, Sequelize) => {
        await queryInterface.createTable("empresas", { 
            id: {
                type: Sequelize.INTEGER,
                allowNull: false,
                autoIncrement: true,
                primarykey: true,
            },

            name: {
                type: Sequelize.STRING,
                allowNull: false,
            },

            site: {
                type: Sequelize.STRING,
                allowNull: false,
                unique: true,
            },

            created_at: {
                type: Sequelize.DATE,
                allowNull: false,
            },

            updated_at: {
                type: Sequelize.DATE,
                allowNull: false,
            }
        
        });
    },

    down: async queryInterface => {
        await queryInterface.dropTable("empresas")
    }
};