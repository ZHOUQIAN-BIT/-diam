# git

## 使用步骤

1. 初始化仓库

   ```shell
   git init 
   ```
  
2. 创建开发分支

    ```shell
    git branch dev
    ```

3. 切换分支

   ```shell
   git checkout dev
   ```

4. 将Day01添加到暂存区

   ```shell
   git add Day01
   ```

5. 将Day01添加到本地仓库

    ```shell
    git commit -m "(feature):Day01"
    ```

6. 查看日志

   ```shell
   git log --oneline
   ```

7. 仅仅删除暂存区文件

    ```shell
    git rm other.log --cache
    ```

8. 生成或查询自己的ssh-key(若不为第一次需要修改文件名)，找到头像下的setting，增加ssh密钥

   ```shell
   ssh-keygen -t rsa -b 4096
   ```

9. 若不为第一次生成密钥,在该目录下

   ```shell
   tail -5 config
   # github
   Host github.com
   HostName github.com
   PreferredAuthentications publickey
   IdentityFile ~/.ssh/test
   ```

10. 将本地仓库的内容传入到远程仓库

      ```shell
      git remote add origin git@github.com:ZHOUQIAN-BIT/-diam.git
      git branch -M main
      git push -u origin main
      ```

11. 将远程仓库的分支master拉取到本地

    ```shell
    git pull git@github.com:ZHOUQIAN-BIT/-diam.git master
    ```

## 解决冲突
