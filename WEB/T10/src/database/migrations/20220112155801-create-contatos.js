'use strict';

module.exports = {
    up: async (queryInterface, Sequelize) => {
        await queryInterface.createTable("contatos", { 
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

            email: {
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
            },

            empresa_id: {
                type: Sequelize.INTEGER,
                references: {
                    model: "empresas", key: "id"
                },
                onUpdate: "CASCADE",
                onDelete: "CASCADE",
                allowNull: false,
            }
        
        });
    },

    down: async (queryInterface) => {
        await queryInterface.dropTable("empresas")
    },
}