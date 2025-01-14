module.exports = {
    dialect: "postgres",
    host: "localhost",
    username: "postgres",
    password: "secret",
    database: "aula-crud",
    define{
        timestamp: true,
        underscored: true,
        underscoredAll: true,
    }
}