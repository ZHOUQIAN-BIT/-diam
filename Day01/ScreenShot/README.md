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
