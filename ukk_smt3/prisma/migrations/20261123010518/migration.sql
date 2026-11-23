/*
  Warnings:

  - A unique constraint covering the columns `[kode_user]` on the table `users` will be added. If there are existing duplicate values, this will fail.

*/
-- AlterTable
ALTER TABLE `users` ADD COLUMN `kode_user` VARCHAR(191) NULL;

-- CreateIndex
CREATE UNIQUE INDEX `users_kode_user_key` ON `users`(`kode_user`);
