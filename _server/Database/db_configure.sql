CREATE TABLE users(
    ID INT PRIMARY KEY NOT NULL,
    USERNAME TEXT,
    PASSWORD TEXT
);
CREATE TABLE clients(username TEXT, phoneNumber TEXT);
--TABLE FOR ONLY NOTES;
CREATE TABLE notes(field TEXT, datatime TEXT);
--TABLE FOR CASES
CREATE TABLE cases(name TEXT, path TEXT, status TEXT);
INSERT INTO users(ID, USERNAME, PASSWORD)
VALUES (2, 'admin2', 'admin2');