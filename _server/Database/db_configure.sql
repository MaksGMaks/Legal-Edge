CREATE TABLE users(
    ID INT PRIMARY KEY NOT NULL,
    USERNAME TEXT,
    PASSWORD TEXT
);
CREATE TABLE clients(username TEXT, phoneNumber TEXT,);
INSERT INTO users(ID, USERNAME, PASSWORD)
VALUES (2, 'admin2', 'admin2');