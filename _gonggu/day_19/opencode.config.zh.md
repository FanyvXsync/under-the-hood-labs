# opencode.json 配置说明

这个文件解释同目录下 `opencode.json` 里每个设置项的作用。`opencode.json` 本身保持严格 JSON 格式，不写注释，避免工具解析失败。

## `$schema`

指定 opencode 配置文件的 JSON Schema 地址。编辑器可以利用它提供自动补全、字段校验和提示。

当前值：`https://opencode.ai/config.json`

## `provider`

用于配置 AI 服务提供商，例如 Anthropic、OpenAI 或其他兼容服务。当前为空对象，表示还没有绑定具体 provider。

之后如果要启用某个服务，可以在这里补充对应 provider 的配置。

## `model`

用于配置模型相关选项，例如默认使用哪个模型、不同任务使用哪个模型等。当前为空对象，表示还没有指定默认模型。

之后可以根据实际使用的 provider 在这里补充模型配置。

## `theme`

控制 opencode 的显示主题。

当前值：`system`，表示跟随系统主题。常见可选值通常包括 `system`、`light`、`dark`，具体以 opencode 当前版本支持为准。
