# 1. Ubuntu ベースのユーザー権限のみのイメージ
FROM ubuntu:22.04

# 2. 必要パッケージをユーザー権限でインストール
RUN apt-get update && apt-get install -y \
    wget curl git unzip build-essential

# 3. DevKitPro pacman をユーザー権限でインストール
# pacman の公式方法だと sudo が必要ですが、ここではユーザーローカルにインストール
ENV DEVKITPRO=/workspace/devkitPro
ENV DEVKITARM=$DEVKITPRO/devkitARM
ENV PATH=$PATH:$DEVKITARM/bin:$DEVKITPRO/tools/bin

RUN mkdir -p $DEVKITPRO
WORKDIR $DEVKITPRO

# pacman をユーザーローカルで使うためのラッパー
RUN wget https://apt.devkitpro.org/devkitpro-pacman.deb && \
    dpkg -x devkitpro-pacman.deb . && \
    rm devkitpro-pacman.deb

# ctrulib3ds をユーザーローカルに配置
# 必要な場合、ソースからビルドする方法もあります
# ここでは curl/wget で直接取得して展開する想定
# （簡易版、必要に応じて GitHub の ctrulib を clone）
